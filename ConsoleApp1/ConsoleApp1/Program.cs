
namespace lab9
{
    class Program
    {
        public static void Main(string[] argc) {
            int a = 1000;
            while (a >= 0) {
                Console.WriteLine($"{a}-7={a-7}");
                a-=7;

                }
        }
    }
}