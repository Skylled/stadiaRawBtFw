// 600ecf50  FUN_600ecf50  size=60 bytes
// --- callers ---
//   60091ddc FUN_60091ddc
//   60090fd0 FUN_60090fd0
// --- callees ---
//   600ecf48 FUN_600ecf48
//   6013d208 thunk_EXT_FUN_0000ac5e
//   600e092c FUN_600e092c


undefined4 FUN_600ecf50(undefined4 *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  FUN_600ecf48();
  iVar1 = FUN_600e092c(param_2);
  if ((param_2 == 0) || (uVar3 = 0, iVar1 != 0)) {
    piVar2 = (int *)FUN_600e092c(0x10);
    if (piVar2 == (int *)0x0) {
      thunk_EXT_FUN_0000ac5e(iVar1);
      uVar3 = 0;
    }
    else {
      *piVar2 = iVar1;
      piVar2[1] = 0;
      piVar2[2] = param_2;
      uVar3 = 1;
      *(undefined2 *)(piVar2 + 3) = 1;
      *param_1 = piVar2;
      *(undefined1 *)((int)param_1 + 0xe) = 0;
    }
  }
  return uVar3;
}


