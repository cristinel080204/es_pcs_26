#pragma once
#include <queue>
#include <stack>

//Coda per il BFS
template <typename T>
class fifo {

    std::queue<T> coda;

public:

    void put(const T& val){ //Implemento la funzione put()
	coda.push(val);
	};
	
    T get() { //Implemento la funzione get()
        T val = coda.front(); 
        coda.pop(); 
        return val; 
    };
	
    bool empty() const{ //Implemento la funzione empty()
	return coda.empty(); 
	};
};

//Stack per il DFS
template <typename T>
class lifo {
	
    std::stack<T> stack;

public:

    void put(const T& val){ //Implemento la funzione put()
	stack.push(val);
	};
	
    T get() { //Implemento la funzione get()
        T val = stack.top(); 
        stack.pop(); 
        return val; 
    };
	
    bool empty() const{  //Implemento la funzione empty()
	return stack.empty(); 
	};
};