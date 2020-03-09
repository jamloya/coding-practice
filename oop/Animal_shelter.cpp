#include<bits/stdc++.h>
using namespace std;


class Animal
{
	private:
		int age;
		string name;
        int  type;  // 0->Dog,1->Cat
	public:
		Animal(string n,int t)
		{
			name=n;
            type=t;
		}
    
          virtual ~Animal()  
        { cout<<"Destructing Animal \n"; }
    
    
        int getType()
        {
            return this->type;
        }
		void setAge(int ord)
		{
			age=ord;
		}
		int getAge()
        {
            return age;
        }
		bool isOlder(Animal* a)
		{
			return this->age < a->getAge();
		}
};


class Dog : public Animal
{
public:
	Dog(string name) : Animal (name,0){}
};

class Cat : public Animal
{
	Cat(string name) : Animal(name,1) {}
};

class AnimalShelter
{
	private:
		list<Dog*> dogs;
		list<Cat*> cats;
		int order;
	
	public:
		void enqueue(Animal a)
		{
			order++;
			a.setAge(order);
			
			if(a.getType()==0)
			{
				dogs.push_back(dynamic_cast<Dog*>(&a)); //downcasting
			}
			else if(a.getType()==1)
			{
				cats.push_back(dynamic_cast<Cat*>(&a)); //downcasting
			}
		}
	
		Animal* dequeueCat()
		{
			Cat *a=cats.front();
			cats.pop_front();
			return a;
		}
		
		Animal* dequeueDog()
		{
			Dog *a=dogs.front();
			dogs.pop_front();
			return a;
		}
		
		Animal* dequeueAny()
		{
            try
            {
			    if(dogs.size()==0 && cats.size()==0)
			    {
			    	throw  0;
			    }
                else if(dogs.size() == 0)
			    {
			    	return dequeueCat();
			    }
			    else if(cats.size()==0)
			    {
			    	return dequeueDog();
		    	}
			
		    	Dog* d=dogs.front();
		    	Cat* c=cats.front();
		    	if(d->isOlder(c))
		    	{
		    		return dequeueDog();
		    	}
		    	else if(c->isOlder(d))
		    	{
		    		return dequeueCat();
		    	}
            }
            catch(int x)
            {
                cout<<"No element left";
            }
	
		}
};


int main()
{
	std::cout<<"hello World";
	return 0;
}
