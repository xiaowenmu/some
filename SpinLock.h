class SpinLock{

public:
	SpinLock():flag(false){}
	
	void lock(){
		bool expected = false;
		while(!flag.compare_exchange_weak(expected,true,std::memory_order_acq_rel)){
			expected = false;
		}
	}

	void unlock(){

		flag.store(false,std::memory_order_acq_rel);
	}

private:
	std::atomic<bool> flag;

};
