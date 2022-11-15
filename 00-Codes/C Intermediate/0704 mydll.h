#pragma  once

//实现两个数相减 函数  
//内部函数 
//int mySub(int a, int b);



//外部函数  导出函数
//生成 .lib  和 .dll
// 静态库中生成的.lib和动态库生成的.lib是不同的，动态库中的.lib只会放变量的声明和 导出函数的声明，函数实现体放在.dll中
__declspec(dllexport)int mySub(int a, int b);
