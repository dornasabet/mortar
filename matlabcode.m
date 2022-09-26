clc ;clear; close all;
x = dlmread('x.txt');
y = dlmread ('y.txt');
plot( x, -(y-400) ,'r--') ;
