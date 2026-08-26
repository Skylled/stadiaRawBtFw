// 600d6e3c  FUN_600d6e3c  size=38 bytes
// --- callers ---
// --- callees ---
//   60066284 keys__60066284


void FUN_600d6e3c(code *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_14 [12];
  
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 1;
    keys__60066284(auStack_14,iVar1);
    (*param_1)(param_2,auStack_14);
    iVar1 = iVar2;
  } while (iVar2 != 0x43);
  return;
}


