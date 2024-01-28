function checkAnagrams(str1, str2) {
  const objStr1 = {};
  if (str1.length !== str2.length) return false;

  for (let ch of str1) {
    objStr1[ch] = (objStr1[ch] || 0) + 1;
  }

  for (let ch of str2) {
    if (!objStr1[ch]) return false;

    objStr1[ch]--;
  }

  return true;
}

console.log(checkAnagrams("hello", "heloo"));
