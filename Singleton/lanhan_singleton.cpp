//懒汉单例模式，调用GetIstance时才创建实例

#include<pthread.h>

class Singleton{
private:
	Singleton(){}
public:
	static Singleton* GetInstance();
private:
	static Singleton* instance_;
	static pthread_mutex_t mutex_t;
}

Singleton* Singleton::instance_=NULL;
pthread_mutex_t Singleton::mutex_t;

Singleton* Singleton::GetInstance(){
	if(instance_==NULL){
		pthread_mutex_lock(&mutex_t);
		if(instance_==NULL)
			instance_=new Singleton();
		pthread_mutex_unlock(&mutex_t);
	}
	return instance_;
}