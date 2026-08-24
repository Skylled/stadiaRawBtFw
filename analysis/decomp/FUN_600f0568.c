// 600f0568  FUN_600f0568  size=114 bytes
// --- callers ---
//   600fd22a FUN_600fd22a
// --- callees ---
//   6009f6c0 FUN_6009f6c0
//   6009ff18 FUN_6009ff18
//   6009ad00 FUN_6009ad00


undefined4 FUN_600f0568(undefined4 param_1,int param_2,char param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_6009ff18(param_1);
  if (((iVar1 == 0) || (param_2 == 0)) ||
     (((param_3 != '\x01' && (((param_3 != '\x02' && (param_3 != '\x04')) && (param_3 != '\x10'))))
      && ((param_3 != '@' && (param_3 != ' ')))))) {
    uVar2 = 0;
  }
  else {
    FUN_6009ad00(param_1,param_3,param_2,0);
    if ((param_3 == '\x02') || (param_3 == ' ')) {
      FUN_6009f6c0(iVar1);
    }
    uVar2 = 1;
  }
  return uVar2;
}


