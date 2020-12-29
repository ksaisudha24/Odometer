#include <vector>

class odometer() {
    private:
       	int size = 0;
       	int length = 0;
	      int position = 0;
        vector<int> readings;

	bool isAscending(int n) {
	    if (n < 10) {
	 	      return true;
	    }
	    if ((n % 10) <= (n / 10) % 10) {
		      return false;
	    }
	    return isAscending(n / 10);
	}
    public:
	odometer(int size) {
	    if (size < 2 || size > 8) return;
	    int start = 1;
	    for (int i = 1; i < size; ++i) start *= 10;
	    for (int i = start; i < 10 * start; ++i) {
		if (isAscending(i)) {
		    this -> length++;
		    readings.push_back(i);
		}
	    }
	    this -> size = size;
	}

	int next(int step = 1) {
	    for (int i = 0; i < step; ++i) {
          this -> position++;
	    }
	    while (this->position >= this->length) {
	        this -> position -= this -> length;
	    }
	    return this->readings[this -> position];
	}

	int prev(int step = 1) {
	    for (int i = 0; i < step; ++i) {
           this -> position--;
	    }
	    while (this->position < 0) {
		       this->position += this -> length;
	    }
	    return this->readings[this->position];
	}

	friend int operator-(const Odometer &a, const Odometer &b) {
	    if (a.size != b.size) return -1;

	    if (a.position >= b.position) {
		        return a.position - b.position;
	    } 
      else {
		       return a.position - b.position + a.length;
	    }
	}
}
