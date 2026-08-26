// 600d5c1c  FUN_600d5c1c  size=32 bytes
// --- callers ---
//   600d614a FUN_600d614a
// --- callees ---
//   600d5c16 FUN_600d5c16


bool FUN_600d5c1c(int *param_1)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = FUN_600d5c16();
  bVar2 = false;
  if (iVar1 != 0) {
    if (*(char *)(*param_1 + 5) == '\x01') {
      bVar2 = *(char *)(*param_1 + 4) == '\x01';
    }
    else {
      bVar2 = false;
    }
  }
  return bVar2;
}


