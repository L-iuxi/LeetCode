int countTestedDevices(int* batteryPercentages, int batteryPercentagesSize) {
    int count = 0;
   for(int i = 0;i <batteryPercentagesSize;i++)
   {
    batteryPercentages[i]-=count;
    if(batteryPercentages[i] < 0)
    {
        batteryPercentages[i] = 0;
    }
    if(batteryPercentages[i] > 0)
    {
        count++;
    }
   } 
   return count;
}