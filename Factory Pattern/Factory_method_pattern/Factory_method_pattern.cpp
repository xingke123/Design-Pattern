//抽象产品类
class SingleCore{
public:
	virtual void Show()=0;
}

//实际产品类

//单核A
class SingleCoreA:public SingleCore{
public:
	void Show(){cout<<"SingleCore A"<<endl;}
}

//单核B
class SingleCoreB:public SingleCore{
public:
	void Show(){cout<<"SingleCore B"<<endl;}
}

//抽象工厂类

class Factory{
public:
	virtual SingleCore* CreateSingleCore()=0;
}

//具体工厂类

//生产A核的工厂
class FactoryA:public Factory{
public:
	SingleCoreA* CreateSingleCore(){return new SingleCoreA();}
}

//生产B核的工厂
class FactoryB:public Factory{
public:
	SingleCoreB* CreateSingleCore(){return new SingleCoreB();}
}