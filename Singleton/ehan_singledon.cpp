//饿汉单例模式，在类初始化时便自行创建了实例
class Singleton{
	private:
	    Singleton(){};
	public:
		static Singleton* GetInstance();
	private:
		static Singleton* instance_=new Singleton();
}

Singleton* Singleton::GetInstance(){
	return instance_;
}