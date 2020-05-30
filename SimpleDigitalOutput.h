class SimpleDigitalOutput {
  private:
    int pin;
    bool state;
  public:
    SimpleDigitalOutput(int pin);
    void onSetup();
    void toggle();
};
