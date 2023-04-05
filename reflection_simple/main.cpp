#include "person.h"
#include "animal.h"
#include "miku.h"
#include "reflector.h"

class ObjectFactory_Miku:public ObjectFactory{
    public:
        ObjectFactory_Miku(){
            std::cout <<"ObjectFactory_Miku() " << std::endl;
        }
        ReflectObject* newInstance(){
            return new Miku();
        };
};
int main(){
    Reflector::reflector().registerFactory("Miku", new ObjectFactory_Miku());
    REFLECT(Animal);
	Person *allen = getNewInstance<Miku>("Miku");
	allen->show();
    Animal* animal = getNewInstance<Animal>("Animal");
    animal->bark();
    delete animal;
	delete allen;
	return 0;
}