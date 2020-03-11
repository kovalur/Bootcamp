class ArithmProgrIterator {
    private:
        int start;
        int step;
        int count;
        int current;
        int counter;
    public:
        ArithmProgrIterator(int start, int step, int count);
        
        void next();
        int value();
        bool over();
        void operator++();
        void operator++(int);
        int operator*();
};
