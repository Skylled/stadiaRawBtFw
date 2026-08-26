// 600d5c70  FUN_600d5c70  size=32 bytes
// --- callers ---
//   600d61c8 FUN_600d61c8
// --- callees ---
//   600d5c6a FUN_600d5c6a


bool FUN_600d5c70(int *param_1)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = FUN_600d5c6a();
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


