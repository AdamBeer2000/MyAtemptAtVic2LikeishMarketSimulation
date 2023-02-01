#pragma once

class A
{

};

template<class t2>
class B :public A<int, t2>
{

};