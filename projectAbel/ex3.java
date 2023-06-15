import java.util.ArrayList;
import java.util.List;

public class Main {

    public static int[] numbers = new int[]{1, 54, 34, 2, 98, 64, 33, 71, 25};

    public static void main(String[] args) {
        
        int[] rezultat_ex3_method1 = ex3_method1(numbers,7);
        for(int i = 0; i < rezultat_ex3_method1.length; i++)
            System.out.print(rezultat_ex3_method1[i] + " "); // it displays 0 at the end

        System.out.println();
        int[] rezultat_ex3_method2 = ex3_method2(numbers, 7);
        for(int i = 0; i < rezultat_ex3_method2.length; i++)
            System.out.print(rezultat_ex3_method2[i] + " "); // no 0 anymore at the end

        System.out.println();
        int[] rezultat_ex3_method3 = ex3_method3(numbers, 7);
        for(int i = 0; i < rezultat_ex3_method3.length; i++)
            System.out.print(rezultat_ex3_method3[i] + " ");
    }

    public static int[] ex3_method1(int[] c, int d){ // not the best method
        int[] help_array = new int[c.length];
        int j = 0; // index for help_array
        for(int i = 0; i < c.length; i++)
            if(c[i] > d)
                help_array[j++] = c[i]; // <=> help_array[j] = c[i]; j++;
        return help_array;
    }

    public static int countNumbersGreaterThanAGivenNumber(int[] c, int d){
        int contor = 0;
        for(int i = 0; i < c.length; i++){
            if(c[i] > d)
                contor++;
        }
        return contor;
    }

    public static int[] ex3_method2(int[] c, int d){
        int[] help_array = new int[countNumbersGreaterThanAGivenNumber(c,d)]; // it helps us in order to know the size of the result array
        int j = 0; // index for help_array
        for(int i = 0; i < c.length; i++)
            if(c[i] > d)
                help_array[j++] = c[i]; // <=> help_array[j] = c[i]; j++;
        return help_array;
    }

    public static int[] ex3_method3(int[] c, int d) {
        List<Integer> help_array = new ArrayList<>();
        for (int i = 0; i < c.length; i++) {
            if (c[i] > d) {
                help_array.add(c[i]);
            }
        }
        return help_array.stream().mapToInt(Integer::intValue).toArray(); // transform ArrayList to an array of int[]
    }
}
