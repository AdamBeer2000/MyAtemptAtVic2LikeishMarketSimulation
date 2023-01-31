#pragma once
template<class t1, class t2>
class A {

};

template<class t3>
class B :public A<int, t3>
{

};