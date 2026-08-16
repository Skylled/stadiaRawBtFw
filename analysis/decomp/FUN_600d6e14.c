// 600d6e14  FUN_600d6e14  size=40 bytes
// --- callers ---
//   60077140 FUN_60077140
//   600d72b8 FUN_600d72b8
//   600d6f24 FUN_600d6f24
//   600d732e FUN_600d732e
//   600d72ec FUN_600d72ec
//   60066370 keys__60066370
//   600d382e FUN_600d382e
//   60065df0 keys__60065df0
//   60051240 main__60051240
//   6005d3b4 thermal__6005d3b4
//   60065eb8 keys__60065eb8
//   600d6eca FUN_600d6eca
//   60078b4c get_device_data__60078b4c
//   6007752c FUN_6007752c
//   6005b1c0 application_state__6005b1c0
//   600d7032 FUN_600d7032
//   60074658 timer__60074658
//   6005b150 application_state__6005b150
//   600d39ba FUN_600d39ba
//   600d70e6 FUN_600d70e6
//   600d6fd8 FUN_600d6fd8
//   600d6f7e FUN_600d6f7e
//   600764fc input_task__600764fc
//   600d708c FUN_600d708c
// --- callees ---
//   601010c8 FUN_601010c8
//   60065db0 FUN_60065db0
//   60065dd8 FUN_60065dd8


bool FUN_600d6e14(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 extraout_r3;
  undefined4 uVar4;
  
  uVar4 = param_1;
  uVar2 = FUN_60065db0();
  uVar3 = FUN_60065dd8(param_1);
  cVar1 = FUN_601010c8(uVar2,uVar3,&stack0xffffffee,extraout_r3,uVar4,param_2);
  return cVar1 == '\0';
}


