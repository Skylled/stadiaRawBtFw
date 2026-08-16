// 60069d50  adapter__60069d50  size=104 bytes
// src: adapter.cc
// --- callers ---
// --- callees ---
//   600d8994 FUN_600d8994
//   60069c10 adapter__60069c10
//   6010165c FUN_6010165c
//   600cbb14 FUN_600cbb14
//   600d8970 FUN_600d8970


/* src: adapter.cc */

void adapter__60069d50(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 local_14;
  
  uVar7 = param_2;
  uVar8 = param_3;
  local_14 = param_4;
  iVar2 = FUN_600d8994(param_1 + 0x110);
  if (iVar2 == 0) {
    uVar5 = 0x3bd;
    uVar6 = DAT_60069dbc;
    uVar4 = DAT_60069db8;
  }
  else {
    cVar1 = FUN_600d8970(param_1 + 0x1ab4,param_2);
    local_14 = CONCAT31(local_14._1_3_,cVar1);
    if (cVar1 == '\0') {
      *(undefined2 *)(param_1 + 0x1ab2) = 0xffff;
      piVar3 = (int *)adapter__60069c10(param_1);
      (**(code **)(*piVar3 + 0x1c))(piVar3,param_3);
      return;
    }
    uVar4 = FUN_600cbb14(&local_14);
    uVar5 = 0x3c8;
    uVar6 = DAT_60069dc4;
  }
  FUN_6010165c(0x28,DAT_60069dc0,uVar5,uVar6,uVar4,uVar7,uVar8);
  return;
}


