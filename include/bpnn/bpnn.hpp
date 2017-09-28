#pragma once
/*
 * Copyright (c) 2016-20017 Max Cong <savagecm@qq.com>
 * this code can be found at https://github.com/maxcong001/logger
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

//将三位二进制数转为一位十进制数
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

#define innode 4      //输入结点数
#define hidenode 100  //隐含结点数
#define outnode 1     //输出结点数
#define trainsample 8 //BP训练样本数

class BpNet
{
  public:
    void train(double p[trainsample][innode], double t[trainsample][outnode]); //Bp训练
    double p[trainsample][innode];                                             //输入的样本
    double t[trainsample][outnode];                                            //样本要输出的

    double *recognize(double *p); //Bp识别

    void writetrain(); //写训练完的权值
    void readtrain();  //读训练好的权值，这使的不用每次去训练了，只要把训练最好的权值存下来就OK

    BpNet();
    virtual ~BpNet();

  public:
    void init();
    double w[innode][hidenode];   //隐含结点权值
    double w1[hidenode][outnode]; //输出结点权值
    double b1[hidenode];          //隐含结点阀值
    double b2[outnode];           //输出结点阀值

    double rate_w;  //权值学习率（输入层-隐含层)
    double rate_w1; //权值学习率 (隐含层-输出层)
    double rate_b1; //隐含层阀值学习率
    double rate_b2; //输出层阀值学习率

    double e;               //误差计算
    double error;           //允许的最大误差
    double result[outnode]; // Bp输出
};


