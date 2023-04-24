def is_palindrome(s):
    begin = 0
    end = len(s) - 1
    isPalin = True

    while begin <= end:
      if s[begin] != s[end]:
        isPalin = False
        break
      begin += 1
      end -= 1

    return isPalin

#Write test cases here
print(is_palindrome("racecar"))
print(is_palindrome("hello"))
print(is_palindrome("hannah"))
print(is_palindrome("madam"))
print(is_palindrome("a"))
