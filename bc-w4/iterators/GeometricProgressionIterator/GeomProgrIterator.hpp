class GeomProgrIterator {
    private:
        int step;
        int count;
        int current;
        int counter;
    public:
        GeomProgrIterator(int start, int step, int count);
        
        void next();
        int value();
        bool over();
        void operator++();
        void operator++(int);
        int operator*();  
};
