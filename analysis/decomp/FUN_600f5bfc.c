// 600f5bfc  FUN_600f5bfc  size=230 bytes
// --- callers ---
// --- callees ---
//   600af814 FUN_600af814
//   600f60ee FUN_600f60ee
//   600f6132 FUN_600f6132
//   600ad8fc FUN_600ad8fc
//   600af8ac FUN_600af8ac
//   600b02e0 FUN_600b02e0
//   600af718 FUN_600af718
//   600f20ac FUN_600f20ac
//   600f610e FUN_600f610e
//   600ada6c FUN_600ada6c


void FUN_600f5bfc(undefined4 param_1,char param_2,undefined2 param_3,char param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = FUN_600af814(param_1,param_4);
  bVar1 = false;
  if (param_4 != '\x01') {
    iVar3 = FUN_600af718(param_1);
    if (iVar3 == 0) {
      iVar4 = FUN_600f20ac(param_1);
      if (iVar4 != 0) {
        FUN_600ada6c(param_1);
      }
    }
    else {
      bVar1 = true;
    }
    if (param_2 == '\0') {
      FUN_600b02e0(param_1,param_3,param_4);
    }
    else if (iVar2 == 0) {
      iVar2 = FUN_600af8ac(param_1,2);
      if (iVar2 != 0) {
        *(undefined2 *)(iVar2 + 0x18) = 4;
        FUN_600f610e(iVar2,4);
        *(undefined2 *)(iVar2 + 0x1a) = 0x17;
        FUN_600ad8fc(iVar2);
        if (bVar1) {
          FUN_600f60ee(iVar3);
        }
      }
    }
    else {
      iVar4 = FUN_600f6132(iVar2);
      if (iVar4 == 2) {
        FUN_600f610e(iVar2,4);
        *(undefined2 *)(iVar2 + 0x1a) = 0x17;
        FUN_600ad8fc(iVar2);
      }
      if (bVar1) {
        FUN_600f60ee(iVar3);
      }
    }
  }
  return;
}


