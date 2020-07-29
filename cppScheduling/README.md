## Random notes

> echo $ACS_CDB
> -> /alma/ACS-2020JUN/acsdata/config/defaultCDB

## Scheduler API

* [ ] a start  # -> console <- Human Operator => Exported (see ICD/idl/Scheduler.idl)
* [ ] b stop
* [ ] c proposalUnderExecution  # 
* [ ] 1 getProposalStatus  # -> db
* [ ] 2 setProposalStatus
* [ ] 3 cameraOn  # -> instruments (see ICD/idl/Instrument.idl)
* [ ] 5 cameraOff 
* [ ] 4 observe  # -> telescope (see ICD/idl/Telescope.idl)



## Vcode Notes

* Shortcut:
  * Ctrl-P -> commnand : Jump to a file press ctrp-P and copy the path (and press Enter)
  * Shift+Alt -> Column selection
  * Ctrl-(K+C) -> Comment text selected
  * Ctrl-(K+U) -> Uncomment text selected
  
* Install plugins:
  * Idl highligthing
  * Cpp plugin from microsoft (has a linter)

## Usefull links:

* Git Remote Repo: https://bitbucket.alma.cl/projects/ACSWS/repos/awv/browse
* BACI Programming a device: https://confluence.alma.cl/display/ICTACS/BACI+Device+Server+Programming+Tutorial
* C++ Hand on: https://confluence.alma.cl/pages/viewpage.action?pageId=54005360
* API design:
  * For ALMA: https://confluence.alma.cl/display/ICTACS/ACS+Workshop+-+Project
  * For Workshop: ./ICD/idl/Scheduler.idl