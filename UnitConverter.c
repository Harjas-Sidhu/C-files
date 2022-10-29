#include <stdio.h>

float in, km, mi, cm, ft, kg, pd;
int opt = 1;

int main()
{
    while (opt != 0)
    {
    o:
        printf("Choose the unit to convert-\n");
        printf("0. Quit\n");
        printf("1.Inches\n");
        printf("2.Kilometer\n");
        printf("3.Centimeter\n");
        printf("4.Feet\n");
        printf("5.Miles\n");
        printf("6.Kilogram\n");
        printf("7.Pound\n");

        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printf("Enter the number of inches you want to convert\n");
            scanf("%f", &in);
            km = in / 39370.0787;
            cm = 100000 * km;
            mi = km / 1.609344;
            ft = cm / 30.48;
            int a;
        l1:
            printf("Choose one-\n");
            printf("0. Quit\n");
            printf("1. Convert to Kilometers\n");
            printf("2. Convert to Centimeters\n");
            printf("3. Convert to Feet\n");
            printf("4. Convert to Miles\n");
            scanf("%d", &a);
            switch (a)
            {
            case 0:
                opt = 0;
                break;
            case 1:
                printf("%f in = %f km\n", in, km);
                break;
            case 2:
                printf("%f in = %f km\n", in, cm);
                break;
            case 3:
                printf("%f in = %f km\n", in, ft);
                break;
            case 4:
                printf("%f in = %f km\n", in, mi);
                break;
                break;
            default:
                printf("Invalid option\n");
                goto l1;
            }
            break;
        case 2:
            printf("Enter the number of kilometers you want to convert\n");
            scanf("%f", &km);
            in = km * 39370.0787;
            cm = 100000 * km;
            mi = km / 1.609344;
            ft = cm / 30.48;
            int b;
        l2:
            printf("Choose one-\n");
            printf("0. Quit\n");
            printf("1. Convert to Inches\n");
            printf("2. Convert to Centimeters\n");
            printf("3. Convert to Feets\n");
            printf("4. Convert to Miles\n");
            scanf("%d", &b);
            switch (b)
            {
            case 0:
                opt = 0;
                break;
            case 1:
                printf("%f km = %f in\n", km, in);
                break;
            case 2:
                printf("%f km = %f cm\n", km, cm);
                break;
            case 3:
                printf("%f km = %f ft\n", km, ft);
                break;
            case 4:
                printf("%f km = %f mi\n", km, mi);
                break;
            default:
                printf("Invalid option\n");
                goto l2;
            }
            break;
        case 3:
            printf("Enter the number of centimeters you want to convert\n");
            scanf("%f", &cm);
            km = cm / 100000;
            in = km * 39370.0787;
            mi = km / 1.609344;
            ft = cm / 30.48;
            int c;
        l3:
            printf("Choose one-\n");
            printf("0. Quit\n");
            printf("1. Convert to Inches\n");
            printf("2. Convert to Kilometers\n");
            printf("3. Convert to Feet\n");
            printf("4. Convert to Miles\n");
            scanf("%d", &c);
            switch (c)
            {
            case 0:
                opt = 0;
                break;
            case 1:
                printf("%f cm = %f km\n", cm, in);
                break;
            case 2:
                printf("%f cm = %f km\n", cm, km);
                break;
            case 3:
                printf("%f cm = %f km\n", cm, ft);
                break;
            case 4:
                printf("%f cm = %f km\n", cm, mi);
                break;
            default:
                printf("Invalid option\n");
                goto l3;
            }
            break;
        case 4:
            printf("Enter the number of feet you want to  convert\n");
            scanf("%f", &ft);
            cm = ft * 30.48;
            km = cm / 100000;
            in = km * 39370.0787;
            mi = km / 1.609344;
            int d;
        l4:
            printf("Choose one-\n");
            printf("0. Quit\n");
            printf("1. Convert to Inches\n");
            printf("2. Convert to Kilometers\n");
            printf("3. Convert to Centimeters\n");
            printf("4. Convert to Miles\n");
            scanf("%d", &d);
            switch (d)
            {
            case 0:
                opt = 0;
                break;
            case 1:
                printf("%f ft = %f km\n", ft, in);
                break;
            case 2:
                printf("%f ft = %f km\n", ft, km);
                break;
            case 3:
                printf("%f ft = %f km\n", ft, cm);
                break;
            case 4:
                printf("%f ft = %f km\n", ft, mi);
                break;
            default:
                printf("Invalid option\n");
                goto l4;
            }
            break;
        case 5:
            printf("Enter the number of miles you want to convert\n");
            scanf("%f", &mi);
            int e;
        l5:
            printf("Choose one-\n");
            printf("0. Quit\n");
            printf("1. Convert to Inches\n");
            printf("2. Convert to Kilometers\n");
            printf("3. Convert to Centimeters\n");
            printf("4. Convert to Feet\n");
            scanf("%d", &e);
            km = mi * 1.609344;
            cm = km * 1000;
            ft = cm / 30.48;
            in = km * 39370.0787;
            switch (e)
            {
            case 0:
                opt = 0;
                break;
            case 1:
                printf("%f mi = %f km\n", mi, in);
                break;
            case 2:
                printf("%f mi = %f km\n", mi, km);
                break;
            case 3:
                printf("%f mi = %f km\n", mi, cm);
                break;
            case 4:
                printf("%f mi = %f km\n", mi, ft);
                break;
            default:
                printf("Invalid option\n");
                goto l5;
            }
            break;
        case 6:
            printf("Enter the number of you want kilograms to convert\n");
            scanf("%f", &kg);
            pd = 2.20462 * kg;
            printf("%fkg = %f pounds\n", kg, pd);
            break;
        case 7:
            printf("Enter the number of you want to pounds convert\n");
            scanf("%f", &pd);
            kg = pd / 2.20462;
            printf("%f pounds = %fkg\n", pd, kg);
            break;
        case 0:
            opt = 0;
            break;

        default:
            printf("Invalid option\n");
            goto o;
            break;
        }
    }

    return 0;
}
