import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class parantheses {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line1 = br.readLine();
        int n= Integer.parseInt(line1);
        String in = br.readLine();
        int[] result = new int[n+1];
        Stack stack = new Stack();
        for (int i=n-1; i>=0; i--){
            if(in.charAt(i)==')' || in.charAt(i)== ']' || in.charAt(i)=='>' || in.charAt(i)== '}') {
                stack.push(in.charAt(i));
            }
                else if(!(stack.isEmpty())){
                char top = (char) stack.peek();
                        if((in.charAt(i) == '(' && top==')') ||
                                (in.charAt(i) == '[' && top==']') ||
                                (in.charAt(i) == '<' && top=='>') ||
                                (in.charAt(i) == '{' && top=='}')){
                            stack.pop();
                            result[i]=2;
                            if(i<n-2){
                                result[i] += result[i+1];
                                result[i] += result[i+result[i]];
                            }
                }else {
                            stack.clear();
                        }
            }
        }
        for (int i=0;i<n;i++)
            System.out.print(result[i]+ " ");
    }
}
