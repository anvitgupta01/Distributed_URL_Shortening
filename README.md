This project is a Distributed URL shortner built using C++. It allows users to shorten long URLs into compact, easy-to-share links, while also providing an efficient redirect mechanism. The shortening process uses a custom hash function, ensuring unique and efficient generation of short URLs.


## Back of the envelope calculation
Assumptions
  - The user requirement is 100 million requests / day or 1200 requests / second.
  - The URL shortener service will run for 10 years. Hence, the total requests in 10 years will be `10 * 365 * 100 million = 365 billion`
  - The characters that will be present in hash value are \[0-9\], \[A-Z\], \[a-z\], !, @, #, $.

Let the length of the hash value for the long URL be N. This must be such that hash collisions will not happen in 10 years.
Or `66^N >= 365 billion`, which gives us the smallest value of N as 7.


## URL Shortening

![](https://github.com/anvitgupta01/Distributed_URL_Shortening/blob/master/images/URL%20Shortening.png)


## URL Redirection

![](https://github.com/anvitgupta01/Distributed_URL_Shortening/blob/master/images/URL%20Redirection.png)


## How to use
1. Install G++ compiler using mingw or mysys

2. Clone the repository using the below command -
   ```
   git clone https://github.com/anvitgupta01/Distributed_URL_Shortening
   ```

4. Run the following command to compile the program and generate executable
   ```
   make
   ```

5. Run the executable to start the service
   ```
   .\URLShortnerAndRedirection.exe
   ```
