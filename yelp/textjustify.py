def fullJustify(words, length):
  text = ' '.join(words)+' '
  if text == ' ':
      return [' '*length]
  res = []
  while text:
      idx = text.rfind(' ', 0, length+1)
      line = text[:idx].split()
      l, n = sum(len(w) for w in line), len(line)
      if n == 1:
          res.append(line[0].ljust(length))
      else:
          s, remainder = divmod(length-l, n-1)
          line[:-1] = [w+' '*s for w in line[:-1]]
          line[:remainder] = [w+' ' for w in line[:remainder]]
          res.append(''.join(line))
      text = text[idx+1:]
  res[-1] = ' '.join(res[-1].split()).ljust(length)
  return res

str = ["This", "is", "an", "example", "of", "text", "justification."]
#str = ["hello",]
L = 16
res = fullJustify(str,L)
for i in res:
  print i
