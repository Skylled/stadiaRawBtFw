// 600ce2c6  FUN_600ce2c6  size=84 bytes
// --- callers ---
//   6005d3b4 thermal__6005d3b4
//   60051240 main__60051240
// --- callees ---
//   601010c8 FUN_601010c8
//   600cb598 key_value_store__600cb598
//   60065db0 FUN_60065db0
//   60065dd8 FUN_60065dd8


char FUN_600ce2c6(undefined4 param_1,undefined4 param_2,uint param_3,int param_4)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uStack_18;
  int local_14;
  
  uVar4 = param_1;
  uVar5 = param_2;
  uStack_18 = param_3;
  local_14 = param_4;
  uVar2 = FUN_60065db0();
  uVar3 = FUN_60065dd8(param_1);
  uStack_18 = uStack_18 & 0xffff;
  cVar1 = FUN_601010c8(uVar2,uVar3,(int)&uStack_18 + 2,0,uVar4,uVar5);
  if (cVar1 == '\0') {
    if (uStack_18._2_2_ == 4) {
      cVar1 = key_value_store__600cb598(uVar2,uVar3,&local_14,4,0);
      if (cVar1 == '\0') {
        *(bool *)param_2 = local_14 != 0;
      }
    }
    else {
      cVar1 = '\x03';
    }
  }
  return cVar1;
}


