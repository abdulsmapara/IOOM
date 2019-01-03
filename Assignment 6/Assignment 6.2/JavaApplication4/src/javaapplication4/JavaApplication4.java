package javaapplication4;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.Scanner;

/**
 *
 * @author abdulsmapara
 */
class Task{
    public void info(Object obj){
        Class cls;
        cls  = obj.getClass();
        System.out.println("Class Name: " + cls.getName());
        Method meth[] = cls.getMethods();
        System.out.println("Methods: ");
        for(Method m : meth){
            System.out.println(m);
        }
        System.out.println("\n");
        
        Constructor constructor[] = cls.getConstructors();
        System.out.println("Constructors: ");
        for(Constructor c : constructor ){
            System.out.println(c);
        }
        System.out.println("\n");
        
        //getDeclaredFields() for all fields
        //getFields() for public fields only
        Field fields[] = cls.getDeclaredFields();
        System.out.println("Fields: ");
        for(Field f : fields){
            System.out.println(f);
        }
        System.out.println("\n");
        
    }
} 
public class JavaApplication4 {

    public static void main(String[] args) {
        Task obj = new Task();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the code to create the object of GreenTea");
        int code = sc.nextInt();
        GreenTea greentea = new GreenTea(code);
       try{
            obj.info(greentea);
       }catch(Exception e){
           System.out.println("Exception " + e);
       }
    }
    
}
