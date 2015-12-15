import pyximport
pyximport.install()

n=12
format_w="%3s"
fs = [i for i in xrange(n+1)]

def last(li):
  return li[-1:] if isinstance(li,list) else li

def debug(fs, p, iter_n):
  print "%4s:" % iter_n,
  for y in fs:
    if y == p: print format_w % last(y),
    else:      print format_w % last(y),
  print

iter_n=0
for p in xrange(2, n+1):
  if fs[p] == p:
    pp = 2*p
    while pp <= n: 
      t = fs[pp]
      l = t if isinstance(t, list) else [t]
      l.append(p)
      fs[pp] = l
      pp = pp + p
      iter_n+=1
      debug(fs, p, iter_n)

print
print "number:", n
print

res = {}
for l in fs: 
  if not isinstance(l, list): continue
  key = tuple(l[1:])
  v = res.setdefault(key,l[0])
  if v == l[0]:
    res[key] = v
  else:
    x = v if isinstance(v, list) else [v]
    x.append(l[0])
    res[key] = x

for r in res: 
  print "%-20s: %s" % (r, res[r])
