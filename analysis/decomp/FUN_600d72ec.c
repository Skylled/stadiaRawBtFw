// 600d72ec  FUN_600d72ec  size=66 bytes
// --- callers ---
//   600d7cdc FUN_600d7cdc
//   60066944 keys__60066944
//   600d738e FUN_600d738e
//   600d732e FUN_600d732e
//   60074658 timer__60074658
//   600d7d1c FUN_600d7d1c
// --- callees ---
//   600d7282 FUN_600d7282
//   600d6e14 FUN_600d6e14
//   60065db0 FUN_60065db0
//   60065dd8 FUN_60065dd8
//   60066070 keys__60066070


void FUN_600d72ec(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int local_14;
  
  local_14 = param_2;
  iVar2 = FUN_600d6e14();
  if (iVar2 == 0) {
    keys__60066070(param_1,param_2,1);
  }
  else {
    uVar3 = FUN_60065db0(param_1);
    uVar4 = FUN_60065dd8(param_1);
    cVar1 = FUN_600d7282(uVar3,uVar4,&local_14);
    if (cVar1 == '\0') {
      *(bool *)param_2 = local_14 != 0;
    }
  }
  return;
}


