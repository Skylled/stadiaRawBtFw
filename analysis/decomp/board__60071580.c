// 60071580  board__60071580  size=112 bytes
// src: board.cc
// --- callers ---
//   60071884 FUN_60071884
//   600cbdc8 xbara__600cbdc8
//   60074658 timer__60074658
// --- callees ---
//   600cbb14 FUN_600cbb14
//   601016f0 FUN_601016f0
//   600d37ac FUN_600d37ac


/* src: board.cc */

bool board__60071580(char param_1,undefined4 param_2)

{
  undefined4 uVar1;
  char local_b0 [4];
  undefined4 local_ac;
  undefined4 local_a8;
  undefined1 *local_a4;
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined1 local_98;
  undefined1 local_97;
  undefined1 local_96 [130];
  char local_14;
  
  if (param_1 != '\0') {
    local_ac = DAT_600715f0;
    local_a8 = 0x58;
    local_a4 = local_96;
    local_a0 = 0x80;
    uStack_9c = 0;
    local_98 = 0;
    local_97 = 0;
    local_96[0] = 0;
    local_b0[0] = param_1;
    local_14 = param_1;
    uVar1 = FUN_600cbb14(local_b0);
    FUN_600d37ac(&local_a4,uVar1);
    FUN_600d37ac(&local_a4,DAT_600715f4);
    FUN_600d37ac(&local_a4,param_2);
    FUN_600d37ac(&local_a4,DAT_600715f8);
    FUN_601016f0(0x28,local_ac,local_a8,&local_a4);
  }
  return param_1 != '\0';
}


