
class Animal {
public:
    ~Animal() = default;

    virtual void walk() = 0;
    virtual void eat() = 0;
    virtual void pet() = 0;
    virtual void call() = 0;
    
    virtual void sleep() = 0;
    virtual void mate() = 0;
    virtual void pounce() = 0;
    virtual unsigned int stomaches() = 0;
    virtual void sniff() = 0; 


};


class Tiger : public Animal {
public:
    ~Tiger() = default;

    void walk() override;
    void eat() override;
    void pet() override;
    void call() override;    

private:
    m_legs;
    m_stomach;
};


class Elephant : public Animal {
public:
    ~Elephant() = default;

    void walk() override;
    void eat() override;
    void pet() override;
    void call() override;     

private:
    m_legs;
    m_stomach;
    m_trunk;
};

class Ocelot : public Animal {
public:
    ~Ocelot() = default;

    void walk() override;
    void eat() override;
    void pet() override;
    void call() override;       

private:
    m_legs;
    m_stomach;
    m_spots;
};



