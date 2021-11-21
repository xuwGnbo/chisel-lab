#include <verilated.h>          // 核心头文件
#include <verilated_vcd_c.h>    // 波形生成头文件
#include <iostream>
#include <fstream>
#include "VALU.h"           // ALU模块类
using namespace std;

VALU* top;                  // 顶层dut对象指针
VerilatedVcdC* tfp;             // 波形生成对象指针

vluint64_t main_time = 0;           // 仿真时间戳
const vluint64_t sim_time = 1024;   // 最大仿真时间戳

int main(int argc, char **argv)
{
    // 一些初始化工作
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    // 为对象分配内存空间
    top = new VALU;
    tfp = new VerilatedVcdC;

    // tfp初始化工作
    top->trace(tfp, 99);
    tfp->open("VALU.vcd");

    while(!Verilated::gotFinish() && main_time < sim_time)
    {
        // 仿真过程
        top->reset = 0;
	for(int a = 0 ; a <= 10 ; ++a){
		for(int b = 0 ; b <= 10 ; ++b){
			for(int op = 0 ; op <= 3 ; ++op){
				top->io_A = a;
				top->io_B = b;
				top->io_alu_op = op;
        			top->eval();            // 仿真时间步进
        			tfp->dump(main_time);   // 波形文件写入步进
       				 main_time++;
			}
		}
	}
    }
    
    // 清理工作
    tfp->close();
    delete top;
    delete tfp;
    exit(0);
    return 0;
}
