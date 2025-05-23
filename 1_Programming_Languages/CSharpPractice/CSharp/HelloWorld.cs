namespace CSharpPractice
// The 'namespace' organizes code and avoids naming conflicts.
// It typically matches the project name, and groups related classes together.

{
    public class HelloWorld
        // This defines a class named 'HelloWorld'.
        // In C#, all code must live inside a class or struct.

    {
        public static void Main(string[] args)
            // 'Main' is the **entry point** of the application.
            // 'public' means accessible from outside.
            // 'static' means it's called without creating an object.
            // 'string[] args' allows passing command-line arguments.

        {
            Console.WriteLine("Hello World");
            // This line prints "Hello World" to the console.
        }
    }
}