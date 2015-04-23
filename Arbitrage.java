/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

/**
 *
 * @author mdshohag
 */
public class Main{

    public static void main(String[] args) {
        InputStream stream=System.in;
        OutputStream outputstream=System.out;
        InputReader in=new InputReader(stream);
        int test=0;
        while (true) {            
            int n=in.NextInt();
            if(n==0)break;
            String s;
            Map<String,Integer>mymap=new HashMap<String, Integer>();
            mymap.clear();
            for(int i=0;i<n;i++)
            {
                s=in.Next();
                mymap.put(s, i);
            }
           int m;
           String source,distantion;
           double cost;
           double [][]data=new double[50][50];
           for(int i=0;i<n;i++)
               for(int j=0;j<n;j++)
                   data[i][j]=0.0;
           m=in.NextInt();
           for(int i=0;i<m;i++)
           {
               source=in.Next();
               cost=in.NextDouble();
               distantion=in.Next();
               int x,y;
               x=mymap.get(source);
               y=mymap.get(distantion);
               data[x][y]=cost;
           }
           for(int k=0;k<n;k++)
               for(int i=0;i<n;i++)
                   for(int j=0;j<n;j++)
                       if(data[i][j]<data[i][k]*data[k][j])
                           data[i][j]=data[i][k]*data[k][j];
           boolean flag=false;
           for(int i=0;i<n;i++)
               if(data[i][i]>1.0)
               {
                   flag=true;
                   break;
               }
           if(flag)
           {
              System.out.printf("Case %d: Yes\n", ++test); 
           }
           else
           {
              System.out.printf("Case %d: No\n", ++test); 
           }
        }
       
    }
}
class InputReader
{
    public BufferedReader reader;
    public StringTokenizer tokenizer;
    public InputReader(InputStream stream)
    {
        reader=new BufferedReader(new InputStreamReader(stream));
        tokenizer=null;
    }
    public String Next()
    {
        while(tokenizer==null || !tokenizer.hasMoreTokens())
        {
            try {
                tokenizer=new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw  new RuntimeException();
            }
        }
        return tokenizer.nextToken();
    }
    public int NextInt()
    {
        return Integer.parseInt(Next());
    }
    public double NextDouble()
    {
        return Double.parseDouble(Next());
    }
    public float NextFloat()
    {
        return Float.parseFloat(Next());
    }
}
