using ManagedDll;
using System.Text.Json;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace Consumer
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<Task> tasks = new List<Task>();
            const int nMaxThread = 4;
            const int nMaxLoop = (int) 5e3;
            const int minItemCount = (int) 550;
            const int maxItemCount = (int) 2250;
            for (int nThread = 0; nThread < nMaxThread; nThread++)
            {
                tasks.Add(Task.Run(() =>
                {
                    int tId = nThread;
                    Random rand = new Random();

                    List<ProcessedData[]> allData = new List<ProcessedData[]>();
                    for (int lap = 0; lap < nMaxLoop; lap++)
                    {
                        int itemCount = rand.Next(minItemCount, maxItemCount);
                        float[] items = new float[itemCount];
                        ProcessedData[] data;
                        for (int i = 0; i < itemCount; i++)
                        {
                            items[i] = rand.NextSingle() * 100f;
                        }
                        ulong outputCount = ConvertWrapper.Convert(items, out data);
                        Console.WriteLine($"{tId}[{lap}] : {outputCount})");
                        allData.Add(data);
                        if((lap % 100) == 0)
                        {
                            Thread.Sleep(50);
                        }
                    }
                    File.WriteAllText($"{tId}.txt", JsonSerializer.Serialize(allData, new JsonSerializerOptions()
                    {
                        IncludeFields = true,
                        WriteIndented = true,
                    }));
                }));
                Thread.Sleep(100);
            }
            Task.WaitAll(tasks.ToArray());
        }
    }
}