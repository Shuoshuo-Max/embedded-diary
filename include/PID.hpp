#pragma once

#include <algorithm>  // 用于 std::clamp
#include <cmath>      // 用于数学函数（如 sin）

namespace control {

/**
 * @brief PID 控制器模板类（Header-Only）
 * @tparam T 数据类型（如 float/double）
 */
template<typename T>
class PID {
public:
    /**
     * @brief 构造函数
     * @param kp 比例系数
     * @param ki 积分系数
     * @param kd 微分系数
     * @param max_output 输出上限
     * @param min_output 输出下限
     */
    PID(T kp, T ki, T kd, T max_output, T min_output)
        : kp_(kp), ki_(ki), kd_(kd), max_(max_output), min_(min_output) {}

    /**
     * @brief 计算 PID 输出
     * @param setpoint 目标值
     * @param actual_value 当前实际值
     * @param dt 时间步长（秒）
     * @return 控制输出（已限幅）
     */
    T compute(T setpoint, T actual_value, T dt) {
        T error = setpoint - actual_value;
        
        // 积分项（含抗饱和）
        integral_ += error * dt;
        integral_ = std::clamp(integral_, min_ / ki_, max_ / ki_);
        
        // 微分项
        T derivative = (error - last_error_) / dt;
        last_error_ = error;
        
        // PID 输出
        T output = kp_ * error + ki_ * integral_ + kd_ * derivative;
        return std::clamp(output, min_, max_);
    }

    // 可选：重置控制器状态
    void reset() {
        integral_ = 0;
        last_error_ = 0;
    }

private:
    T kp_, ki_, kd_;     // PID 系数
    T max_, min_;        // 输出限幅
    T integral_{0};      // 积分项累积
    T last_error_{0};    // 上一次误差
};

} // namespace control