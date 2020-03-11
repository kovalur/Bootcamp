class NaturalNumbersIterator {
    private:
        int limit;
        int current;
    public:
        NaturalNumbersIterator(int limit);
        
        void next();
        int value();
        bool over();
        void operator++();
        void operator++(int);
        int operator*();
};
