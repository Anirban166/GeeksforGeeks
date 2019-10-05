TOH(n,from,to,aux)
{ TOH(n-1,from,aux,to);
  move nth disc from 'from' to 'to'
  TOH(n-1,aux,to,from);
}
