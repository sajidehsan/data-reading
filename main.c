#include <stdio.h>
#include <stdlib.h>
#define rows_length 750


int main()
{
	FILE* tp;
	int i = 0;
	int males = 0, females = 0, mr = 0, fr = 0, amage = 0, afage = 0, hage = 0, amweig = 0, afweig = 0, yage, obesep = 0, obesem = 0, obesef = 0;
	int mbm1, mbm2, mbm3, ambm1 = 0, ambm2 = 0, ambm3 = 0, fbm1, fbm2, fbm3, afbm1 = 0, afbm2 = 0, afbm3 = 0,
		aagemn = 0, aagefn = 0;
	int averagebmim=0, averagebmif=0;
	int below30fem=0,below30mal=0,above60fem=0,above60mal=0,between30and60fem=0,between30and60mal=0;
	float rate, mbmi, ambmi = 0, fbmi, afbmi = 0;

	char gender[rows_length];
	int age[rows_length];
	float height[rows_length];
	float weight[rows_length];
	char result[rows_length];
	int zip[rows_length];
	char dataToBeRead[50];


	tp = fopen("Data.txt", "r");            //check file open successfully or not
	if (tp == 0)
	{
		printf("error\n");
		exit(1);
	}
	else
	{
		while (fgets(dataToBeRead, 50, tp) != NULL)
		{
			sscanf(dataToBeRead, "%c %d %f %f %c %d", &gender[i], &age[i],&height[i], &weight[i], &result[i], &zip[i]);
			i++;
		}
		yage = age[0];
		for (int j = 0; j < i; j++)
		{
			if (gender[j] == 'M')                 //check gender
			{
				males++;                                   //numbers of males
				if (result[j] == '+')
				{
					mr++;                                  //male result
					amage = amage + age[j];
					amweig = amweig + weight[j];
					mbmi = (weight[j] / (height[j]*height[j])) * 703;
					ambmi = ambmi + mbmi;
					if (mbmi >= 30)
					{
						obesem++;
					}
					if(age[j]>=80&&mbmi>=30)
                    {
                        obesep++;
                    }
					if (age[j] < 30)
					{
						mbm1 = (weight[j] / (height[j]*height[j])) * 703;
						ambm1 = ambm1 + mbm1;
					    below30mal++;
                    }
					if (age[j] >= 30 && age[j] <= 60)
					{
						mbm2 = (weight[j] / (height[j]*height[j])) * 703;
						ambm2 = ambm2 + mbm2;
					    between30and60mal++;
                    }
					if (age[j] > 60)
					{
						mbm3 = (weight[j] / (height[j]*height[j])) * 703;
						ambm3 = ambm3 + mbm3;
					    above60mal++;
                    }
				}
				else
				{
					aagemn = aagemn + age[j];
				}
			}
			if (gender[j] == 'F')
			{
				females++;
				if (result[j] == '+')
				{
					fr++;
					afage = afage + age[j];
					afweig = afweig + weight[j];
					fbmi = (weight[j] / (height[j]*height[j])) * 703;
					afbmi = afbmi + fbmi;
					if (fbmi >= 30)
					{
						obesef++;
					}
					if(age[j]>=80&&fbmi>=30)
                    {
                        obesep++;
                    }
					if (age[j] < 30)
					{
						fbm1 = (weight[j] / (height[j]*height[j])) * 703;
						afbm1 = afbm1 + fbm1;
					    below30fem++;
                    }
					if (age[j] >= 30 && age[j] <= 60)
					{

						fbm2 = (weight[j] / (height[j]*height[j])) * 703;
						afbm2 = afbm2 + fbm2;
						between30and60fem++;
                    }
					if (age[j] > 60)
					{
						fbm3 = (weight[j] / (height[j]*height[j])) * 703;
						afbm3 = afbm3 + fbm3;
						above60fem++;
                	}
				}
				else
				{
					aagefn = aagefn + age[j];
				}
			}
			if (result[j] == '+')
			{
				if (age[j] > hage)
				{
					hage = age[j];
				}
				if (age[j] <= yage)
				{
					yage = age[j];
				}

			}

		}

		float a;

		a = males + females;
		float b;
		b = mr + fr;
		rate = b / a;
       if(mr!=0)
       {
          amage = amage / mr;
          amweig = amweig / mr;
          averagebmim = ambmi / mr;
       }
        if (fr!=0)
           {
            afage = afage / fr;
            afweig = afweig / fr;
           averagebmif = afbmi / fr;
           }
       if(aagemn!=0)
       {
		aagemn = aagemn / (males - mr);
       }
       if(aagefn!=0)
       {
		aagefn = aagefn / (females - fr);
       }
        if(below30mal!=0)
        {
		ambm1 = ambm1/below30mal;
        }
        if(between30and60mal!=0)
        {
        ambm2 = ambm2 / between30and60mal;
        }
        if(above60mal!=0)
        {
        ambm3 = ambm3 / above60mal;
        }
		if(below30fem!=0)
        {
		afbm1 = afbm1 / below30fem;
        }
        if(between30and60fem!=0)
        {
		afbm2 = afbm2 / between30and60fem;
        }
        if(above60fem!=0)
        {
		afbm3 = afbm3 / above60fem;
        }
		printf
		("1.How many males have been tested and how many of them tested positive?\n");
		printf("  Total males tested is: %d\n", males);
		printf("  Total males tested positive is: %d\n\n", mr);
		printf
		("2.How many females have been tested and how many of them tested positive?\n");
		printf("  Total females tested is : %d\n", females);
		printf("  Total females tested positive is: %d\n\n", fr);
		printf
		("3.What is the average age of the males who tested positive?\n");
		printf("  Average age of males who testes positive is: %d\n\n",
			amage);
		printf
		("4.What is the average age of the females who tested positive?\n");
		printf("  Average age of females who testes positive is: %d\n\n",
			afage);
		printf("5. What is the oldest age of a person who tested positive?\n");
		printf("  Oldest age of person who tested positive is: %d\n\n", hage);
		printf
		("5.What is the youngest age of a person who tested positive?\n");
		printf("  Youngest age of person who tested positive is: %d\n\n", yage);
		printf
		("7.Compare the average age of the males who tested positive to the average age of the males who didnot test positive.\n");
		printf("  Average age of male who tested positive is: %d\n", amage);
		printf("  Average age of male who didnot test positive is: %d\n\n",
			aagemn);
		printf
		("8.Compare the average age of the females who tested positive to the average age of the females who did not test positive.\n");
		printf("  Average age of females who tested positive is: %d\n",
			afage);
		printf("  Average age of females who didnot test positive is: %d\n\n",
			aagefn);
		printf
		("9.What's the average weight of the males who tested positive?\n");
		printf("  Average weight of the male who tested positive is: %d\n\n",
			amweig);
		printf
		("10.What's the average weight of the females who tested positive?\n");
		printf("  Average weight of the females who tested positive is: %d\n\n",
			afweig);
		printf
		("11.Determine the average BMI for the males who tested positive.\n");
		printf("  Average BMI for male is: %d\n\n", averagebmim);
		printf
		("12.Determine the average BMI for the females who tested positive.\n");
		printf("  Average BMI for females is: %d\n\n", averagebmif);
		printf
		("13.Determine how many of the males who tested positive are obese.\n");
		printf("  Obese males are: %d\n\n", obesem);
		printf
		("14.Determine how many of the females who tested positive are obese.\n");
		printf("  Obese females are: %d\n\n", obesef);
		printf
		("15.Determine how many people who are 80 or older who tested positive are obese.\n");
		printf("   persons who are 80 or older who tested positive are obese are: %d\n\n", obesep);
		printf
		("16.Determine what the average BMI is for males who tested positive in the following three groups: under 30, between 30-60, and over 60.\n");
		printf("  Under 30 is: %d\n", ambm1);
		printf("  Between 30 and 60 is: %d\n", ambm2);
		printf("  Above 60 is: %d\n\n", ambm3);
		printf
		("17.Determine what the average BMI is for females who tested positive in the following three groups: under 30, between 30-60, and over 60.\n");
		printf("  Under 30 is: %d\n", afbm1);
		printf("  Between 30 and 60 is: %d\n", afbm2);
		printf("  Above 60 is: %d\n\n", afbm3);
		printf
		("18.What is the average rate of infection for all of the people who were tested?\n");
		printf("  Average rate is: %f\n", rate);

	}

	fclose(tp);
	return 0;
}
