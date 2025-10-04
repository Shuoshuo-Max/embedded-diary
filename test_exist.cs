using System;
using System.IO;
class Test {
    static void Main() {
        Console.WriteLine(File.Exists(\"dist/MiniBalanceCar.hpp\") ? \"文件存在，合并成功！\" : \"文件不存在\");
    }
}
