pipeline {
  agent {
    dockerfile true  
  }
  stages {
    stage('Example') {
      steps {
        echo 'Hello World!'
        sh 'echo myCustomerEnvVar = $myCustomerEnvVar'
      }
    }
    stage('Build') {
      steps {
        sh './build.sh' 
      }
    }
  }
}
