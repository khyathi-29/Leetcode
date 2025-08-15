class H2O {
     Semaphore canPrintHydrogen,hasPrintHydrogen;

    public H2O() {
        canPrintHydrogen = new Semaphore(2);
        hasPrintHydrogen = new Semaphore(0);
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
		canPrintHydrogen.acquire();
        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        releaseHydrogen.run();
        hasPrintHydrogen.release();

    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
         hasPrintHydrogen.acquire(2);
        // releaseOxygen.run() outputs "O". Do not change or remove this line.
		releaseOxygen.run();
        canPrintHydrogen.release(2);
    }
}