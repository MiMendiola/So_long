# So_Long

<div>

  ![Project](https://img.shields.io/badge/Project-So_Long-blue)
  ![Licence](https://img.shields.io/badge/Licence-MIT-orange)
  ![Version](https://img.shields.io/badge/Version-1.0-green)
  <a href="https://github.com/MiMendiola/Ft_printf/tree/main/Documentation/README.es.md" >
    <img src="https://img.shields.io/badge/Cambiar_Idioma-Español-purple" align="right">
  </a>

</div>

This project aims to reprogram the practical function `printf` and learn about using `variadic functions` in C. We can create as many files as we want and keep this in mind while creating our `.h` and `Makefile`.

Let's start by discussing our main file, `ft_printf`, where we will have our function as per the subject, using `variadic functions`, and looking for a `%` to identify the type of variable requested. The other function is a `type selector`, where we will also use a variadic function and work with the next character after the `%` found earlier. From that point, we will select the function type depending on the letter found.

Our `ft_printf_basics` will have basic functions that will help us print a single character, or string, or display numbers with and without a sign. Here, we can modify functions previously used in `Libft` while considering the character counter returned, which will be returned in each function.

In `ft_printf_others`, we placed functions needed to display hexadecimal numbers and others related to pointer addresses, always considering our counter.

---

## Table of Contents

[FT_PRINTF.C](./ft_printf.c)

[FT_PRINTF_BASICS.C](./ft_printf_basics.c)

[FT_PRINTF_OTHERS.C](./ft_printf_others.c)

[FT_PRINTF.H](./ft_printf.h)

---

## Recommendations

Investigate how to work with `variadic functions` and what possibilities of use we have with them.

Have a clear idea of what `type of conversions` we need to perform and how to make those conversions. For this, you can seek help from some functions in the library, but remember that you cannot include `Libft`.

Find out and understand how `hexadecimal numbers` work, how they became what they are, and how we can use them to our advantage. Similarly, with `pointer addresses`, understand how they are formed and how to use them.

Keep in mind that we have to return the total sum of what is printed on the screen, so it would be good to have a `counter` that helps us.

---

## Contact

If you have any questions, suggestions, or comments about ft_printf, feel free to contact me:

- Email: <a href="mailto:mglmendiol@gmail.com" style="text-decoration: none; color:#fff">mglmendiol@gmail.com</a>
- LinkedIn: <a href="https://www.linkedin.com/in/mimendiola/" style="text-decoration: none; color:#fff;">https://www.linkedin.com/in/mimendiola/</a>
