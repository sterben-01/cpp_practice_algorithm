/*
*static_cast转换
语法：
@ type a = static_cast<type>(b);
将其他类型的b转换成type类型的a。
!static_cast用于基本数据类型以及有继承关系的子类与父类的指针或者引用之间的类型转换

*dynamic_cast转换
语法：
@type a = dynamic_cast<type>(b);
将其他类型的b转换成type类型的a。
!dynamic_cast只能用于子类类型转化为父类类型。子类指针转父类指针，是由大到小，是类型安全的。而父类指针转子类指针，由小到大，是类型不安全的。

*const_cast转换
语法：
@type a = dynamic_cast<type * / &>(b);
模板参数列表那里要填写指针或者引用。
!const_cast用于针对基本数据类型的指针、引用以及自定义类型对象的指针进行const权限的增加或者去除（去除是不改变员数据，会将结果给到一个新的值）。

*reinterpret_cast 强制类型转换
reinterpret_cast是强制类型转换，任何类型指针都可以转化为其他类型指针。

*/