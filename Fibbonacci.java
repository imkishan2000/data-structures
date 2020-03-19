class Fibbonacci
{
    long prev;
    long first;
    long cur;

    Fibbonacci()
    {
        this(0,1);
    }

    Fibbonacci(long value1,long value2)
    {
        first=value1;
        prev=value2-value1;
    }

    protected long nextValue()
    {
        long temp=prev;
        prev=cur;
        cur+=temp;
        return cur;
    }
    public static void main(String[] args)
    {
        Fibbonacci fb=new Fibbonacci(4,6);
        for(int i=0;i<13;i++)
        {
            System.out.println(fb.nextValue());
        }

    }
}