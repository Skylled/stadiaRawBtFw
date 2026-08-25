// 600fd83a  FUN_600fd83a  size=138 bytes
// --- callers ---
//   60094dc4 FUN_60094dc4
// --- callees ---
//   60094d24 FUN_60094d24
//   60094f58 FUN_60094f58
//   600fdab8 FUN_600fdab8
//   600ef390 FUN_600ef390
//   600ef7f8 FUN_600ef7f8


void FUN_600fd83a(undefined4 param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = *param_2;
  iVar2 = FUN_60094f58(*(undefined1 *)(param_2 + 7));
  if (iVar2 != 0) {
    if (*(char *)((int)param_2 + 0xf) == '\0') {
      FUN_600fdab8(param_2,iVar2);
    }
    else {
      iVar3 = FUN_600ef390(*(undefined1 *)(param_2 + 7),param_2 + 4,*(undefined1 *)(param_2 + 8));
      if (iVar3 == 0) {
        FUN_600ef7f8(iVar2,0x80,param_2 + 4,0xffff,*(undefined1 *)(param_2 + 8),0,param_2,param_1);
      }
      else {
        FUN_60094d24(iVar3,uVar1,param_2);
      }
    }
  }
  return;
}


