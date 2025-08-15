class ZeroEvenOdd {
    private int n;
    Semaphore semZero;
    Semaphore semOdd ;
    Semaphore semEven;
    boolean isOdd;

    
    public ZeroEvenOdd(int n) {
        this.n = n;
        semZero = new Semaphore(1);
        semOdd = new Semaphore(0);
        semEven = new Semaphore(0);
        isOdd = true;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for(int i=0;i<n;i++)
        {
            semZero.acquire();
            printNumber.accept(0);
            if(isOdd) semOdd.release();
            else semEven.release();
            isOdd=!isOdd;
        }
        
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        int numTimes = n/2;
        int initialNumber = 2;
        for(int i=0;i<numTimes;i++)
        {
            semEven.acquire();
            printNumber.accept(initialNumber);
            initialNumber += 2 ;
            semZero.release();

        }
        
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        int numTimes = (n+1)/2;
        int initialNumber = 1;
        for(int i=0;i<numTimes;i++)
        {
            semOdd.acquire();
            printNumber.accept(initialNumber);
            initialNumber += 2 ;
            semZero.release();

        }
    }
}