#include <verilated.h>       // 核心头文件
#include <verilated_vcd_c.h> // 波形生成头文件
#include <iostream>
#include <fstream>
#include "VMUL.h" // 模块类
using namespace std;

VMUL *top;   // 顶层dut对象指针
VerilatedVcdC *tfp; // 波形生成对象指针

vluint64_t main_time = 0;         // 仿真时间戳
void nextTick();

int main(int argc, char **argv)
{
   // 一些初始化工作
   Verilated::commandArgs(argc, argv);
   Verilated::traceEverOn(true);

   // 为对象分配内存空间
   top = new VMUL;// VMultiplier;
   tfp = new VerilatedVcdC;

   // tfp初始化工作
   top->trace(tfp, 99);
   tfp->open("VMUL.vcd");
   
   top->clock = true;

   // 仿真过程
   int cntLoop = 0, cntT=0;
   for (unsigned int a = 0; a < 16; ++a)
   {
       cout << a << " * ";
      for (unsigned int b = 0; b < 16; ++b)
      {
         top->io_multiplier = a;
         top->io_multiplicand = b;
         top->io_inputValid = true;
	 nextTick(); 
	 top->io_inputValid = false;
	 do{
		 nextTick();
	 }while(!top->io_outputValid);
	 
	 if (b) cout << ", ";
	 bool check = (unsigned int)top->io_product == a * b;
	 cout << b << (check ? "T" : "F");
	 cntLoop++;
	 cntT += check;
      }
      cout << ";" << endl;
   }
   cout << "Loop: " << cntLoop << ", True: " << cntT << ", False: " << cntLoop - cntT << endl;

   // 清理工作
   tfp->close();
   delete top;
   delete tfp;
   exit(0);
   return 0;
}

void nextTick(){
	for(int i = 0 ; i < 2 ; ++ i ){
		top->clock = !top->clock;
		top->eval();
		tfp->dump(main_time);
		main_time++;
	}	
}
